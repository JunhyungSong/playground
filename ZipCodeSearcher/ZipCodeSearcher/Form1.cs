using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml.XPath;

namespace ZipCodeSearcher
{
    class ZipCodeInfo
    {
        private uint zipCode;
        private string cityName;
        private string state;

        public uint ZipCode { get => zipCode; }
        public string CityName { get => cityName; }
        public string State { get => state; }

        public ZipCodeInfo(UInt32 zipCode, String cityName, String state)
        {
            this.zipCode = zipCode;
            this.cityName = cityName;
            this.state = state;
        }
    }

    class TrieNode<T>
    {
        private T value;
        private Dictionary<char, TrieNode<T>> children;

        public T Value { get => value; }
        internal Dictionary<char, TrieNode<T>> Children { get => children; }

        public TrieNode(T value)
        {
            this.value = value;
            this.children = new Dictionary<char, TrieNode<T>>();
        }
    }

    public partial class Form1 : Form
    {
        private TrieNode<List<ZipCodeInfo>> header;

        public Form1()
        {
            InitializeComponent();

            this.header = ParseXMLDatabaseToTrie(@"zipcode.xml");
        }

        private TrieNode<List<ZipCodeInfo>> ParseXMLDatabaseToTrie(string xmlFilePath)
        {
            TrieNode<List<ZipCodeInfo>> header = new TrieNode<List<ZipCodeInfo>>(null);

            XPathDocument xmlDocument = new XPathDocument(xmlFilePath);
            XPathNavigator xmlNavigator = xmlDocument.CreateNavigator();

            xmlNavigator.MoveToRoot();

            if (xmlNavigator.HasChildren)
            {
                xmlNavigator.MoveToFirstChild();

                if (xmlNavigator.HasChildren)
                {
                    xmlNavigator.MoveToFirstChild();

                    do
                    {
                        xmlNavigator.MoveToFirstChild();
                        uint zipCode = uint.Parse(xmlNavigator.Value);

                        xmlNavigator.MoveToNext();
                        string cityName = xmlNavigator.Value;

                        xmlNavigator.MoveToNext();
                        string state = xmlNavigator.Value;

                        ZipCodeInfo zipCodeInfo = new ZipCodeInfo(zipCode, cityName, state);

                        TrieNode<List<ZipCodeInfo>> currentNode = header;
                        for (int i = 0; i < cityName.Length; i++)
                        {
                            TrieNode<List<ZipCodeInfo>> findNode = null;
                            if (!currentNode.Children.TryGetValue(cityName[i], out findNode))
                            {
                                if (i == cityName.Length - 1)
                                {
                                    currentNode.Children.Add(cityName[i], new TrieNode<List<ZipCodeInfo>>(new List<ZipCodeInfo> { zipCodeInfo }));
                                }
                                else
                                {
                                    findNode = new TrieNode<List<ZipCodeInfo>>(new List<ZipCodeInfo>());
                                    currentNode.Children.Add(cityName[i], findNode);
                                    currentNode = findNode;
                                }
                            }
                            else
                            {
                                if (i == cityName.Length - 1)
                                {
                                    findNode.Value.Add(zipCodeInfo);
                                }
                                else
                                {
                                    currentNode = findNode;
                                }
                            }                            
                        }

                        xmlNavigator.MoveToParent();
                    }
                    while (xmlNavigator.MoveToNext());
                }                
            }

            return header;
        }

        private void TextBox1_TextChanged(object sender, System.EventArgs e)
        {
            if (sender.GetType() == typeof(TextBox))
            {
                this.listView1.Items.Clear();

                string inputText = ((TextBox)sender).Text.ToUpper();
                TrieNode<List<ZipCodeInfo>> currentNode = this.header;

                for (int i = 0; i < inputText.Length; i++)
                {
                    TrieNode<List<ZipCodeInfo>> findNode = null;
                    if (currentNode.Children.TryGetValue(inputText[i], out findNode))
                    {
                        currentNode = findNode;
                    }
                    else
                    {
                        currentNode = null;
                        break;
                    }
                }

                if (currentNode != null && currentNode != this.header)
                {
                    List<ListViewItem> items = new List<ListViewItem>();
                    TraversalForNode(currentNode, ref items);
                    ListViewItem[] arrItems = items.ToArray();
                    this.listView1.BeginUpdate();
                    this.listView1.Items.AddRange(arrItems);
                    this.listView1.EndUpdate();
                }
            }
        }

        private void TraversalForNode(TrieNode<List<ZipCodeInfo>> node, ref List<ListViewItem> items)
        {
            if (node.Value != null)
            {
                foreach (ZipCodeInfo info in node.Value)
                {
                    string[] row = { info.CityName, info.ZipCode.ToString(), info.State };
                    ListViewItem item = new ListViewItem(row);
                    items.Add(item);
                }
            }            

            foreach (TrieNode<List<ZipCodeInfo>> child in node.Children.Values)
            {
                TraversalForNode(child, ref items);
            }
        }
    }
}

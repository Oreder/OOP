using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Random_Multiplication
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private int x, y;

        private void button1_Click(object sender, EventArgs e)
        {
            Random number = new Random();
            x = number.Next(1, (int)Math.Pow(10, (int)numericUpDown1.Value) - 1);
            y = number.Next(1, (int)Math.Pow(10, (int)numericUpDown2.Value) - 1);

            textBox1.Text = x.ToString(); textBox2.Text = y.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox3.Text = ((double)(x * y)).ToString("F0");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
        }
    }
}

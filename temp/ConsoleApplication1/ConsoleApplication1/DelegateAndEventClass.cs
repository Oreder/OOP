using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DelegateAndEvent
{
    internal delegate void ExampleDelegate(string s);

    class Example
    {
        public Example(ExampleDelegate ed)
        {
            for (int i = 0; i < 10; i++)
                ed(i.ToString());
        }

        public int addition(int a, int b)
        {
            return a + b;
        }

        public int subtraction(int a, int b)
        {
            return a - b;
        }

        public void hello(string s)
        {
            Console.WriteLine("Hello {0}!", s);
        }

        public void goodbye(string s)
        {
            Console.WriteLine("Good bye, {0}!", s);
        }
    }
}

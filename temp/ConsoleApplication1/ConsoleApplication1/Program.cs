using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DelegateAndEvent;

namespace ConsoleApplication1
{
    public delegate int calculation(int a, int b);

    internal delegate void message(string s);

    class Program
    {
        static void Main(string[] args)
        {
            //Example e = new Example();
            //int a = 5;
            //int b = 25;

            ////Console.Write("Result: {0}", e.addition(a, b));
            //calculation calculationDelegate = new calculation(e.addition);

            ////Console.Write("Result: {0} + {1} = {2}", a, b, calculationDelegate.Invoke(a, b));
            //Console.WriteLine("Result: {0}", calculationDelegate(a, b));

            //string s = "Khanh";

            //message Mes = new message(e.hello) + new message(e.goodbye);

            //Mes(s);

            ExampleDelegate ed = DelegateAsParams;
            Example e0 = new Example(ed);

            Console.ReadLine();

            Example e1 = new Example(delegate(string s)
                                    {
                                        Console.WriteLine(s);
                                    });
            Console.ReadLine();
        }

        public static void DelegateAsParams(string s)
        {
            Console.WriteLine(s);
        }
    }
}

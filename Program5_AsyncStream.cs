using System;

namespace ConsoleApp5_Asyn_Stream
{
    /* exmaple 5 
        * pj92singh 
        * Prabhjit Singh 
        * 
        * using sutdent class again but with Async Streams
        */
    public class Student
    {
        //either intalize or use nullable refernce types
        public string? FirstName { get; set; }
        public string? LastName { get; set; }
        public string? Email { get; set; }
        public string? GPA { get; set; }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}

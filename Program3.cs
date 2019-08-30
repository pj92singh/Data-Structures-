using System;

namespace ConsoleApp3
{
    /* exmaple 3 
     * pj92singh 
     * Prabhjit Singh 
     * 
     * using sutdent class again but with other data types 
     * testing null "?" and console execution 
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
            var student = new Student()
            {
                FirstName = "John"
                //LastName = "Smith"

            };
            Console.WriteLine($"The sudent is called {student.FirstName} {student.LastName.ToUpper()}");
            Console.ReadKey(); 
        }
    }
}

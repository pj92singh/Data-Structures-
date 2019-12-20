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
        async static void Main(string[] args)
        {
            //await is needed
            //for something that is using async streams
            await foreach(var student in GetStudentAsync())
            {
                Console.WriteLine($"{Student.FirstName} {Student.LastName}");
            }
            Console.ReadKey();
        }
        async static IAsyncEnumerable<Student> GetStudentAsync()
        {
            var list = new List<Student>()
            {
                new Student() {FirstName = "John", LastName = "Doe", Email = "john.doe@test.com", GPA = 2.98},
                new Student(){FirstName = "Bob", LastName = "Olsn", Email = "bob.o@test.com", GPA = 3.22}
            };
            foreach(var Student in list)
            {
                await Task.Delay(3000);
                yield return Student; 
                //returns the stream of students
            }

        }
    }
}

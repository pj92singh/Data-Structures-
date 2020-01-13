using System; 

namespace ConsoleApp6
{
         /* exmaple 6 
        * pj92singh 
        * Prabhjit Singh 
        * 
        * using ranges and testing StringBuilder
        * testing behaviour on cs
        */
    class Program
        {
            static void Main(string[] args)
            {
                testRanges();
                Console.ReadKey();
            }
            private static void testRanges(){
                //testing ranges 
                string[] letters = { "A", "B", "C", "D" ,"E" , "F", "G", "H", "I", "J", "K", "L", "M" ,"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}; 
                //first range a to Z 
                range range1 = 0..;
                //next range is from D to Z
                range range2 = 3..;
                //3rd range B to Y 
                range range3 = 1..^1; 
                //4th range A to X      
                range range4 = 0..^2;

                StringBuilder builder = new StringBuilder();
                range range5 = 1..4;
                foreach(var letter in letters[range5])
                {
                    builder.append($"{letter}"");
                }
                    Console.Writeline(builder.toString());
                }
        }

 }
using System;
using System.Collections.Generic;
using System.Text;
using ConsoleApp8.Exceptions; 


namespace ConsoleApp8
{
    /* pj92singh
     *consoleApp 8 
     *
     *
     **/
    class Program
    {
        /* app 8 will use the interface IReporter 
         * Report class and then the related custom exception classes
         * to use the pattern concenpts of C# and show the correct logs
         
          the relationship is as follows; 
          ****class and interface structure *****
            // IReporter.cs interface // 
            => use in Reporter.cs
            both "use"/import the Execptions class 
            >> Exceptions << 
            -uses namespace of Exceptions 
            DB // File // Http

            Main ConsoleApp8 (using execptions)
          */
        static void Main(string[] args)
        {
           try {
                //testing DB error
                //throw new DatabaseException("DB connection failed", "API DB");
                throw new HttpException("HTTP error", "http//www.gitsite.com", 503); 
                /*we can also test other exeception
                throw new FileSystemException("File not found");
                */
            }
            catch (Exception err){
                //testing with level error
                IReporter reporter = new Reporter();
                reporter.Report(err, "Something went wrong in the main method", SeverityLevel.Error);
                reporter.Report(err, "Something went wrong in the main method", SeverityLevel.Info);
                //we can contiune testing with other memebers of severitylevel and different exceptions
                /*
                reporter.Report(err, "Something went wrong in the main method", SeverityLevel.Critical);
                reporter.Report(err, "Something went wrong in the main method", SeverityLevel.Warning);
                reporter.Report(err, "Something went wrong in the main method", SeverityLevel.Trace);
                */
            }
            Console.ReadKey();
        }
    }
}

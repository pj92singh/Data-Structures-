using System;
using System.Collections.Generic;
using System.Text;
using ConsoleApp8.Exceptions; 

namespace ConsoleApp8
{
    /* interface file 
     * this will use the execeptions class
     * and it will be the base file for severity level
     */
    public enum SeverityLevel
    {
        Trace = 0,
        Info = 1,
        Warning = 2,
        Error = 3,
        Critical = 4
    }
    public interface IReporter
    {
        //all classes can use this method from this interface
        //original method
        //public void Report(Exception ex, string description, SeverityLevel level);
        //PART 2 
        //it was changed to add the exeception paramter after
        //VS studio will now warn us => reproter class doesn't have this added yet
        public void Report(Exception ex, string description, SeverityLevel level); 
    }
}

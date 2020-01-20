using ConsoleApp8.Exceptions;
using System;
using System.Collections.Generic;
using System.Text;


namespace ConsoleApp8
{
    /* pj92singh 
     * using/extended to the Interface we have this Reporter class using
     the method and the enum
     *(use "ctrl . " to auto populate the public method 
     & also the switch case automatically
     *
     *PART 2 
     * since execption class was added we need to update the paramters used
     * in the write line method and in the SWITCH cases as well
     * NOW the only thing is we don't know which exeception we are taking in
     *...is it a DB exception? or is it file? or http?
     * to find out a paramters value you can use the "IS" operator
     , or use the "AS" operator to CAST
     ** check the WRITELINE func for the switch case that is used to handle this
     *
     **/
    public class Reporter : IReporter
    {
        public void Report(Exception ex, string description, SeverityLevel level)
        {
            switch (level)
            {
                case SeverityLevel.Trace:
                    WriteLine(ex, ConsoleColor.Cyan, $"Trace: {description}"); 
                    break;
                case SeverityLevel.Info:
                    WriteLine(ex, ConsoleColor.DarkBlue, $"Info: {description}");
                    break;
                case SeverityLevel.Warning:
                    WriteLine(ex, ConsoleColor.DarkMagenta, $"Warning: {description}");
                    break;
                case SeverityLevel.Error:
                    WriteLine(ex, ConsoleColor.Red, $"Error: {description}");
                    break;
                case SeverityLevel.Critical:
                    WriteLine(ex, ConsoleColor.Yellow, $"Critical: {description}");
                    break;
                default:
                    break;

            }
        }
        private void WriteLine(Exception ex, ConsoleColor color, string text)
        {
            /* PART 2 using the execption and be able to cast using the switch case
             * to handle the pattern // this allows us to handle different patterns
             * and variables with the correct type
             */
            switch (ex)
            {
                case DatabaseException dbex:
                    text = $"[Database - {dbex.DbName} ]: " + text;
                    break;
                case FileSystemException fsex:
                    text = $"[FS - ]: " + text;
                    break;
                case HttpException httpex:
                    text = $"[Http error - {httpex.StatusCode}]:  " + text;
                    break; 
            }
            var currentColor = Console.ForegroundColor;
            Console.ForegroundColor = color;
            Console.WriteLine(text);
            Console.ForegroundColor = currentColor;

        }
    }
}
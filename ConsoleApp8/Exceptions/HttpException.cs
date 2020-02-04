using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp8.Exceptions
{
    /* HttpExeception class
     * will use the related Reporter class 
     * example exception class 3 for http requests and errors
	* uses the a public method for throwing http system errors
	* will be used in the main program along with the reporter interface
	*/*/
    public class HttpException : Exception
    {
        public string Url { get; }
        public int StatusCode { get; }
        public HttpException(string message, string url, int statusCode) : base(message)
        {
            Url = url;
            StatusCode = statusCode;
        }
    }
}

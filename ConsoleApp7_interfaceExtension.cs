/*******************************************************************
*
*
* Name: ConsoleApp7_interfaceExtension.cs 
* Version: 1.0.0
*
*
* Author: Prabhjit Singh 
* Purpose:  part 3 consoleapp
-using the new c# extending property 
-this allows us to have interface members and extend them
-this way the method can be invoked via other classes without adding the code
_
 ********************************************************************/

 public interface IReporter{
     Task Warning(string description, Exeption ex);
     Task Error(string description, Exeption ex);
     Task Critical(string description, Exeption ex);
     //this last interface memeber will be extended in other classes that extend this interface
     Task Trace(string description) => Console.WriteLine($"Trace:" {description}"");
     // further test the invocation of this
 }
 /************* 
 i.e
 *next class will use the interface & use Filereporter to save logs to a separate file,
 * for each different type
 */
public class Filereporter : IReporter{
    private const string _criticalFilePath = "./critical.log";
    private const string _errorFilePath = "./error.log";
    private const string _warningFilePath = "./warning.log";

    public async Task Critical(string description, Execption ex){
        await LogErrorToFile(_criticalFilePath, $"CRITICAL: {description}: {ex.Data.ToString()}");
    }
    public async Task LogErrorToFile(string filePath, stirng line){
        //function to write the error to the file
        /*
        using (var writer = new StreamWriter(filePath, true)){
            await writer.WriteLineAsync(line);
        }
        */
    }
}

 /************* */

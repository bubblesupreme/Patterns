
package IOC;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class FileLogger extends Logger{

    static private File              file;
    static private FileWriter        stream;
    
    public FileLogger(ILogFormatProvider provider, String file_name)
    {
        super(provider);
        FileLogger.setFile(file_name);
    }
    
    static private void setFile(String file_name)
    {
        file = new File (file_name);
      try
      {
        file.createNewFile ();
        stream = new FileWriter (file);
      }
      catch (IOException e)
      {
        System.err.println ("Failded to create logging file");
        System.err.println (e.toString());
      }
    }
    
    @Override
    public void log(String msg, LogLevel level) 
    {
        setLevel(level);
        string(msg);
        writeToFile();
        super.clearBuff();
    }

    @Override
    public void log(String msg, Object obj, LogLevel level) 
    {
        setLevel(level);
        string(msg, obj);
        writeToFile();
        super.clearBuff();
    }

    @Override
    public void log(String msg, Object[] objs, LogLevel level) 
    {
        setLevel(level);
        string(msg,objs);
        writeToFile();
        super.clearBuff();
    }
    
    @Override
    public void enter (String class_name, String func_name)
    {
        super.enter(class_name, func_name);
        writeToFile();
        super.clearBuff();
    }
    
    @Override
    public void log (Throwable err)
    {
        super.log(err);
        writeToFile();
        super.clearBuff();
    }

    @Override
    public void leave ()
    {
        super.leave();
        writeToFile();
        super.clearBuff();
    }

    @Override
    public void close() {
        try
        {
            stream.close();
        }
        catch (IOException e) {}
    }
    
    private void writeToFile()
    {
        try
        {
            stream.write(string_buff.toString());
            stream.flush ();
        }
        catch (IOException e) {}
    }
}

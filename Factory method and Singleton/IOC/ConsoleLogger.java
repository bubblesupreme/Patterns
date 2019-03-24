package IOC;

public class ConsoleLogger extends Logger
{    
    
    public ConsoleLogger(ILogFormatProvider provider)
    {
        super(provider);
    }
    
    @Override
    public void log(String msg, LogLevel level) 
    {
        setLevel(level);
        string(msg);
        writeToConsole();
        super.clearBuff();
    }

    @Override
    public void log(String msg, Object obj, LogLevel level) 
    {
        setLevel(level);
        string(msg, obj);
        writeToConsole();
        super.clearBuff();
    }

    @Override
    public void log(String msg, Object[] objs, LogLevel level) 
    {
        setLevel(level);
        string(msg,objs);
        writeToConsole();
        super.clearBuff();
    }
    
    @Override
    public void enter (String class_name, String func_name)
    {
        super.enter(class_name, func_name);
        writeToConsole();
        super.clearBuff();
    }

    @Override
    public void leave ()
    {
        super.leave();
        writeToConsole();
        super.clearBuff();
    }
    
    @Override
    public void log (Throwable err)
    {
        super.log(err);
        writeToConsole();
        super.clearBuff();
    }
    
    @Override
    public void close() 
    {}
    
    private void writeToConsole()
    {
        System.out.println(string_buff.toString());
    }
}

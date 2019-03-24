
package IOC;

import java.util.Arrays;


public abstract class Logger implements ILogger
{
    protected ILogger.LogLevel  level;
    protected StringBuilder string_buff;
    ILogFormatProvider provider;

    public Logger(ILogFormatProvider provider)
    {
        string_buff = new StringBuilder();
        this.provider = provider;
    }

    protected void setLevel(LogLevel level)
    {
        this.level = level;
    }
    
    @Override
    public void enter(String class_name, String func_name)
    {
        setLevel(LogLevel.DEBUG);
        provider.formatLog(string_buff);
        string_buff.append("Entered ").append(class_name).append(".")
                .append(func_name);
        newLine();
    }
    
    @Override
    public void log(Throwable err)
    {
        setLevel(LogLevel.THROW);
        provider.formatLog(string_buff);
        string_buff.append("Throwed ").append(err.toString ());
        newLine();
    }

    @Override
    public void leave()
    {
        setLevel(LogLevel.DEBUG);
        provider.formatLog(string_buff);
        string_buff.append("Leaved function");
        newLine();
    }

    protected void string( String msg ) 
    {
        provider.formatLog(string_buff);
        String msgs[] = msg.split ("\n");
        for (String msg_ : msgs)
        {
            shiftLevel(level.ordinal());
            string_buff.append(msg_);
            newLine();
        }
    }
    
    protected void string(String msg, Object obj) 
    {
        string(msg);
        shiftLevel(level.ordinal());
        string_buff.append( obj.toString());
        newLine();
    }
    
    protected void string(String msg, Object[] objs)
    {
        string(msg);
        shiftLevel(level.ordinal());
        string_buff.append( Arrays.toString(objs));
        newLine();
    }
    
    protected void clearBuff()
    {
        string_buff.setLength(0);
    }
    
    protected void shiftLevel(int shift)
    {
        for (int i=0; i<shift; i++)
        {
            string_buff.append("    ");
        }
    }
    
    protected void newLine()
    {
        string_buff.append("\n");
    }
    
    @Override
    public ScopeLogger scope()
    {
        return new ScopeLogger(this);
    }
    
    @Override
    abstract public void close();
}
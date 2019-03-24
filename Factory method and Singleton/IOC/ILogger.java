
package IOC;

public interface ILogger {
    enum LogLevel
    {
        INFO,
        DEBUG,
        WARNING,
        THROW,
        ERROR
    };
    public void log ( String msg, LogLevel level );
    public void log ( String msg, Object obj, LogLevel level );
    public void log ( String msg, Object[] objs, LogLevel level );
    public void enter (String class_name, String func_name);
    public void log (Throwable err);
    public void leave ();
    public void close();
    public ScopeLogger scope();
}

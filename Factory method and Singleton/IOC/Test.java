package IOC;

import java.io.IOException;

public class Test {

    public static void main(String[] args) {
        {
            Hub hub = new Hub();
            hub.bind(ILogFormatProvider.class).to(DataLogProvider.class, true);
            hub.bind(ILogger.class).to(ConsoleLogger.class, false);
            ILogger logger = hub.resolve(ILogger.class);
            try (ScopeLogger scope_logger=logger.scope())
            {
                logger.log("Hi!", ILogger.LogLevel.INFO);
                logger.enter(Test.class.getCanonicalName(), "main");
                logger.log("This is int : ", 5, ILogger.LogLevel.DEBUG);
                ILogger logger2 = hub.resolve(ILogger.class);
                try (ScopeLogger scope_logger2=logger2.scope())
                {
                    logger2.log("Error level, logger2",ILogger.LogLevel.ERROR);
                    logger.log("Debug level, logger",ILogger.LogLevel.DEBUG);
                }
            }
            catch (IOException e){}
        }
        
        {
            Hub hub = new Hub();
            hub.bind(ILogFormatProvider.class).to(SimpleLogProvider.class, true);
            hub.bind(String.class).to(String.class, ()->"log.txt" ,true);
            hub.bind(ILogger.class).to(FileLogger.class ,true);
            ILogger logger_single = hub.resolve(ILogger.class);
            try (ScopeLogger scope_logger=logger_single.scope())
            {
                logger_single.log("These are ints : ", new Integer[3],
                        ILogger.LogLevel.INFO);
                ILogger logger_single2 = hub.resolve(ILogger.class);
                try (ScopeLogger scope_logger2=logger_single2.scope())
                {
                    logger_single2.log("Is this the single logger? -", 
                            logger_single==logger_single2,ILogger.LogLevel.DEBUG);
                    logger_single.leave();
                }
            }
            catch (IOException e){}
        }
    }
    
}






package HTTPServer;

import java.util.HashMap;
import java.util.Map;

public class Router {
    Map<String, IController> router;
    
    public Router()         
    {
        router = new HashMap<String, IController>();
    }
    
    public void add_route(String url, IController controller)
    {
        router.put(url, controller);
    }
    
    public IController choiceController(String url)
    {
        return router.get(url);
    }
    
}

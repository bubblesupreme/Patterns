
package IOC;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Supplier;

class Hub implements IHub 
{
    private final Map<String, Supplier<Object>> container = new HashMap<>();
    private final Map<String, Object> singletonContainer = new HashMap<>();

    public Hub() 
    {
        init();
    }

    public final void init() 
    {
        bind(IHub.class).to(Hub.class, () -> this, true);
    }

    public <T> BindProxy bind(Class... c) 
    {
        return new BindProxy<>(c);
    }

    @Override
    public <T> T resolve(Class<T> c) 
    {
        String name = c.getCanonicalName();
        if (container.containsKey(name)) {
            Supplier<Object> tt = container.get(name);
            return (T) tt.get(); 
        }
        throw new RuntimeException("Can not resolve " + name);
    }

    public class BindProxy<T> {
        Class<T>[] ifaces;

        private BindProxy(Class<T>[] c) {
            ifaces = c;
        }

        public <A> void to(Class<A> c, boolean singleton) {
            to(c, () -> createObject(c), singleton);
        }

        public <A> void to(Class<A> c, Supplier<Object> fabric, boolean singleton) 
        {
            for (Class<T> iface : ifaces) {
                container.put(iface.getCanonicalName(), () -> {
                    if (singleton) {
                        return createSingleton(c, fabric);
                    } else {
                        return fabric.get();
                    }
                });
            }
        }

        private <A> Object createObject(Class<A> c) 
        {
            Constructor<?> a = c.getDeclaredConstructors()[0];
            a.setAccessible(true);
            Object[] params = Arrays.stream(a.getParameterTypes()).
                    map(Hub.this::resolve).toArray();
            try {
                return a.newInstance(params);

            } catch (IllegalAccessException | InvocationTargetException | 
                    InstantiationException e) {
                System.exit(-1);
            }
            return null;
        }

        private <A> Object createSingleton(Class<A> c, Supplier<Object> fabric) 
        {
            String name = c.getCanonicalName();
            if (!singletonContainer.containsKey(name)) {
                singletonContainer.put(name, fabric.get());
            }
            return singletonContainer.get(name);
        }
    }
}



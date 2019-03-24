
package IOC;

interface IHub 
{
    <T> T resolve(Class<T> c);
}

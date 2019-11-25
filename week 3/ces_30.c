#include <unistd.h>
#include <

int *ces(char *a)
{
    int i = 0;
    while (a != '\0')
    {
        a[i] += 30;
        i++;
    }
    printf("%s", a);
    return (0);
}

int main()
{
    char *a;

    a = "&QKPI JCNH QH UQOGVJKPI";
    ces(a);

}

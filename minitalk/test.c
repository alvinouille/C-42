int main(int ac, char **av)
{
    int     pid;
    int     i;
    char    *str;
    char    *octet;
    int     j;

    pid = ft_atoi(av[1]);
    str = av[2];
    i = 0;
    j = 0;
    kill(pid, SIGUSR1);
    kill(pid, SIGUSR2);
    while (str[i])
    {
        octet = binaire(str[i]);
        printf("octet = %s\n", octet);
        while (octet[j])
        {
            if (octet[j] == '0')
            {
                printf("0");
                kill(pid, SIGUSR1);
            }
            else
            {
                printf("1");
                kill(pid, SIGUSR2);
            }
            j++;
        }
        j = 0;
        free(octet);
        i++;
    }
}
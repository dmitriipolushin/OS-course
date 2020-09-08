
int main(int argc, char const *argv[])
{
    int n = 13;
    int f = fork();
    int f1 = fork();
    if (f == 0)
    {
        printf("Hello from child [%d - %d]\n", f, n);
    }
    else
    {
        printf("Hello from parent [%d - %d]\n", f, n);
    }
    /*
    function fork() return next values:
        0 - returns to a child process and it is the PID of parent
        positive value - returns to a parent process and it is the PID of child
    firstly we execute the parent process and get as output:
        "Hello from parent ['child id' - n]"
    sencondly we execute the child process in which for return id of parent whuch is 0:
        "Hello from child [0 - n]"
    */
    return 0;
}

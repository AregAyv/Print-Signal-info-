#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <ucontext.h>
#include <pwd.h>



void handle_sigusr1(int sig) {
    pid_t sender_pid = getpid();
    std::cout << "PID: " << sender_pid << std::endl;

    uid_t sender_uid = getuid();
    std::cout << "Sender UID: " << sender_uid << std::endl;

    struct passwd *pw = getpwuid(sender_uid);
    std::cout << "Sender user name: " << pw->pw_name << std::endl;

    ucontext_t context;
    getcontext(&context);

    std::cout << "EIP: " << context.uc_mcontext.gregs[REG_RIP] << std::endl;
    std::cout << "EAX: " << context.uc_mcontext.gregs[REG_RAX] << std::endl;
    std::cout << "EBX: " << context.uc_mcontext.gregs[REG_RBX] << std::endl;
}

int main() {

    pid_t pid = getpid();
    std::cout << "PID: " << pid << std::endl;
    signal(SIGUSR1, handle_sigusr1);


    while (true) {
        sleep(10);
    }

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

void ntp_off() {

	int pid;
	pid = fork();
	if(pid == -1) {
		perror("fork");
		exit(1);
	}
	if(pid == 0) {
		execlp("timedatectl", "timedatectl",
			       "set-ntp", "true", NULL);
		perror("timedatectl");
		exit(1);
	}
	wait(NULL);
}
void ntp_restart() {
	int pid;
	pid = fork();
	if(pid == -1) {
		perror("fork");
		exit(1);
	}
	if(pid == 0) {
	execlp("sudo", "sudo", "service", 
			"ntp", "restart", NULL);
	perror("sudo");
	exit(1);
	}
	wait(NULL);
}

int main()
{
	time_t t_before = time(NULL);
	printf("%s\n", ctime(&t_before));
	ntp_off();
	time_t t_after = time(NULL);
	sleep(10);
	ntp_restart();
	double diff = difftime(t_after, t_before);
	printf("%f seconds\n", diff); 
	return 0;
}

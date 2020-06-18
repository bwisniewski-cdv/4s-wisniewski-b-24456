#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]){
    FILE *directory, *reg;
    DIR *etc, *sys;
    struct dirent *dir;
    struct stat *sta;
    char path[256];
    //tworzenie folderu
    mkdir("results", (S_IRUSR | S_IWUSR | S_IXUSR));
    //Otwarcie plikow
    directory = fopen("results/etc_dir.out", "w");
    reg = fopen("results/sysconfig.out", "w");
    //Etc_Dir
	etc = opendir("/etc");
    if(etc != NULL)
	{
        while((dir = readdir(etc)) != NULL)
		{
            if(dir->d_type == DT_DIR)
			{
                fprintf(directory, "%s\n", dir->d_name);
            }
        }
        closedir(etc);
    }
    //Sysconfig
    sys = opendir("/etc/sysconfig/");
    if(sys != NULL)
	{
        while((dir = readdir(sys)) != NULL)
		{
            if(dir->d_type == DT_REG)
			{
                memset(path,'\0',256);
                strcat(path,"/etc/sysconfig/");
                strcat(path, dir->d_name);
                printf("%s\n", path);
                if(!(sta->st_mode & S_IROTH) || !(sta->st_mode & S_IWOTH) || !(sta->st_mode & S_IXOTH))
				{
                    fprintf(reg, "%s\n", dir->d_name);
                }
            }
        }
        closedir(sys);
    }
    //Zamkniecie plikow
    fclose(directory);
    fclose(reg);
    return 0;
}

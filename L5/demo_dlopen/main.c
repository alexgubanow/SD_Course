#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <libgen.h>
#include <string.h>

typedef int (*AddFunc)(int, int);
typedef long (*pow2Func)(int, int);
int fixCWD();

int main()
{
  if (fixCWD())
  {
    return 1;
  }
  // Load the dynamic library
  void *handle = dlopen("./libmylib.so", RTLD_LAZY);
  if (!handle)
  {
    fprintf(stderr, "Error opening library: %s\n", dlerror());
    return 1;
  }

  AddFunc add = (AddFunc)dlsym(handle, "add");
  if (!add)
  {
    fprintf(stderr, "Error loading function: %s\n", dlerror());
    dlclose(handle);
    return 1;
  }

  int result = add(5, 3);
  printf("Result: %d\n", result);
  pow2Func pow2 = (pow2Func)dlsym(handle, "pow2");
  if (!pow2)
  {
    fprintf(stderr, "Error loading function: %s\n", dlerror());
    dlclose(handle);
    return 1;
  }
  pow2(1, 1);
  dlclose(handle);
  return 0;
}

int fixCWD()
{
  // Retrieve the path to the executable
  char executablePath[2048] = "\0";
  if (readlink("/proc/self/exe", executablePath, sizeof(executablePath)) == -1)
  {
    fprintf(stderr, "Error retrieving executable path\n");
    return 1;
  }
  // Change the current working directory to the directory containing the executable
  char *executableDir = dirname(strdup(executablePath));
  if (chdir(executableDir) == -1)
  {
    fprintf(stderr, "Error changing working directory\n");
    free(executableDir);
    return 1;
  }
  free(executableDir);
  return 0;
}
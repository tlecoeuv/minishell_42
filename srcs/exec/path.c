#include "../../includes/minishell.h"

void get_absolute_path(char **cmd)
{
  char    *path;
  char    *bin;
  char    **path_split;
  int     i;

  i = 0;
  path = ft_strdup(getenv("PATH"));
  if (**cmd != '/' && strncmp(*cmd, "./", 2) != 0)
  {
    path_split = ft_split(path, ":");
    free(path);
    while (path_split[i])
    {
      if(!(bin = malloc(sizeof(char) * (ft_strlen(path_split[i]) + ft_strlen(*cmd) + 2))))
        return ;
      ft_strcat(bin, path_split[i]);
  		ft_strcat(bin, "/");
  		ft_strcat(bin, *cmd);
      if (!(test_file(bin))
      free(bin);
      i++;
    }
    free_array(path_split);
    free(*cmd);
    *cmd = bin;
  }
  else
    free(path);
}

int   test_file(char *)
{
  
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTIN_system_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:32:34 by vimafra-          #+#    #+#             */
/*   Updated: 2025/08/02 17:03:17 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_var_node *new_system_var(char *input)
{
    t_var_node *new_node;
    
    new_node = (t_var_node *)malloc(sizeof(t_var_node));
	if (!new_node)
		return (NULL);
    new_node->name = ft_strdup(input);
    //new_node->content = ft_strdup(getenv(input)); // por alguma razão essa linha não funciona no codespace
    //comentar as duas linhas abaixo na máquina da 42, e usar a de cima
    char *env_value = getenv(input);
    new_node->content = env_value ? ft_strdup(env_value) : ft_strdup("");
    new_node->set_status = 1;
    new_node->next = NULL;
    return (new_node);
}

char **system_var_array(void)
{
    char *sys_var_src;
    char **sys_var;
    
    sys_var_src = "SYSTEMD_EXEC_PID/SSH_AUTH_SOCK/SESSION_MANAGER/GNOME_TERMINAL_SCREEN/LANG"
    "/XDG_CURRENT_DESKTOP/PWD/FT_HOOK_NAME/DEFAULTS_PATH/FT_HOOK_PATHNAME/XDG_GREETER_DATA_DIR"
    "/LIBVIRT_DEFAULT_URI/GPG_AGENT_INFO/DESKTOP_SESSION/QT_IM_MODULE/XDG_MENU_PREFIX"
    "/XDG_SESSION_PATH/USER/DBUS_SESSION_BUS_ADDRESS/DOCKER_HOST/SSH_AGENT_LAUNCHER"
    "/GTK_MODULES/XDG_CONFIG_DIRS/GTK_IM_MODULE/XDG_SESSION_DESKTOP/QT_ACCESSIBILITY"
    "/GNOME_DESKTOP_SESSION_ID/MANDATORY_PATH/XDG_SEAT_PATH/KRB5CCNAME/GNOME_TERMINAL_SERVICE"
    "/LOGNAME/PATH/XDG_DATA_DIRS/XMODIFIERS/XDG_RUNTIME_DIR/XDG_SESSION_TYPE/SHELL"
    "/DBUS_STARTER_BUS_TYPE/HOME/VTE_VERSION/COLORTERM/XAUTHORITY/DBUS_STARTER_ADDRESS"
    "/DISPLAY/TERM/GDMSESSION/XDG_SESSION_CLASS/SHLVL/OLDPWD/ANDROID_HOME/_";
    sys_var = ft_split(sys_var_src, '/');
    if (!sys_var)
        return (NULL);
    return (sys_var);
}

int set_system_var(t_var_node **list)
{
    t_var_node	*new_node;
    int i;
    char **sys_var;
    
    i = 0;
    sys_var = system_var_array();
    if (!sys_var)
        return (-1);
    while (sys_var[i] != NULL)
    {
        new_node = new_system_var(sys_var[i]);
        if (!new_node || add_var(list, new_node) == -1)
            return (-1);
        free(sys_var[i]);
        i++;
    }
    free(sys_var);
    return (0);
}
#include "../include/philo.h"

void data_debug(t_data *data)
{
    printf("philo_num: %d\n", data->philo_num);
    printf("time_to_die: %d\n", data->time_to_die);
    printf("time_to_eat: %d\n", data->time_to_eat);
    printf("time_to_sleep: %d\n", data->time_to_sleep);
    printf("must_eat: %d\n", data->must_eat);
}

int main(int argc, char **argv)
{
    t_data data;

    if (argc <= 4 || argc > 6)
    {
        printf("%s\n", INPUT_ERR_3);
        return (1);
    }
    else if (parse_arg(&data, argc, argv))
    {
        printf("%s\n", INPUT_ERR_1);
        return (1);
    }
    else
        data_debug(&data);
    return (0);
}
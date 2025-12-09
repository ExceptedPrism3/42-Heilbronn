def ft_count_harvest_iterative():
    days_until = int(input('Days until harvest: '))
    day = 1
    while day in range(days_until):
        print(f'Day {day}')
        day += 1
    print(f'Day {day}')
    print('Harvest time!')

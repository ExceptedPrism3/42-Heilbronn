def ft_count_harvest_recursive(current=1, days_until=None):
    if days_until is None:
        days_until = int(input('Days until harvest: '))

    print(f'Day {current}')
    current += 1

    if current == days_until:
        print(f'Day {current}')
        print('Harvest time!')
        return
    else:
        ft_count_harvest_recursive(current=current, days_until=days_until)

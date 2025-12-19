def ft_count_harvest_recursive(current=1, days_until=None):
    if days_until is None:
        days_until = int(input('Days until harvest: '))

    print(f'Day {current}')
    # Base case: if we've reached the target day, announce harvest
    if current >= days_until:
        print('Harvest time!')
        return
    # Recursive step: move to the next day
    ft_count_harvest_recursive(current=current + 1, days_until=days_until)

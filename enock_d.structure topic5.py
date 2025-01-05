freelancer_data = []

def add_freelancer(freelancer):
    freelancer_data.append(freelancer)
    print(f'Freelancer {freelancer} added.')

def remove_freelancer(freelancer):
    if freelancer in freelancer_data:
        freelancer_data.remove(freelancer)
        print(f'Freelancer {freelancer} removed.')
    else:
        print(f'Freelancer {freelancer} not found.')

def display_freelancers():
    print('Current freelancers:')
    for freelancer in freelancer_data:
        print(f' - {freelancer}')

add_freelancer('Freelancer A')
add_freelancer('Freelancer B')
display_freelancers()

remove_freelancer('Freelancer A')
display_freelancers()

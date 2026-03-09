import csv
import random
import sys
import os

output_folder = "generated_sources"

# Read the routers from routers_template.csv
nodes_a = []
nodes_b = []
# Pfad ggf. anpassen, falls routers.csv woanders liegt, hier original belassen
with open('sources/links.csv', mode='r') as file:
    csv_reader = csv.reader(file)
    next(csv_reader)  # Skip header
    for row in csv_reader:
        nodes_a.append(row[0])
        nodes_b.append(row[2])

# Get number of generations
n = int(sys.argv[1]) if len(sys.argv) > 1 else 1

# Loop for generating traffic files
for i in range(n):
    suffix = '' if i == 0 else str(i)
    # Nur noch traffic file definieren
    traffic_file = f'traffic{suffix}.csv'
    traffic_file = os.path.join(output_folder, traffic_file)
    
    traffic = []
    amounts = list(range(200000,600001,10000))
    durations = list(range(6,11))

    indices = list(range(len(nodes_a)))

    number_of_indices = random.choice(list(range(1,len(indices)+1)))
    random_indices = random.sample(indices, number_of_indices)

    # Logic remains: Iterate through routers and create random flows
    for index in random_indices:
        src = nodes_a[index]
        # Pick a destination that is not the source
        dest = nodes_b[index]
        
        amount = random.choice(amounts)
        packets = amount // 1000
        duration = random.choice(durations)
        protocol = 'udp'
        
        # Packet size calculation (logic from previous context implies this is needed)
        # Im originalen Skript wurde packetSize hier nicht explizit berechnet, 
        # aber im Traffic-Array auch nicht geschrieben (siehe traffic.append unten).
        # Ich belasse es beim Original-Schema:
        
        traffic.append([src, dest, amount, packets, duration, protocol])


    # Write traffic{suffix}.csv
    with open(traffic_file, mode='w', newline='') as file:
        csv_writer = csv.writer(file)
        # Header matching the structure used in your simulation
        csv_writer.writerow(['SrcRouter', 'DestRouter', 'Amount', 'Number of Packets', 'Duration', 'Protocol'])
        for t in traffic:
            csv_writer.writerow(t)

    print(f"Generated {len(traffic)} traffic entries in {traffic_file}")
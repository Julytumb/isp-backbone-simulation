import os
import re

def delete_files(file_prefix, file_extension):
    # Pfad zum aktuellen Skript
    script_directory = os.path.dirname(os.path.abspath(__file__))
    # Pfad zum 'outputs' Ordner (ein Level höher, dann in 'outputs')
    directory = os.path.join(script_directory, '..', 'outputs')
    directory = os.path.abspath(directory)
    
    # Prüfen, ob das Verzeichnis existiert
    if not os.path.exists(directory):
        print(f"Directory {directory} not found.")
        return

    # Regex Pattern angepasst für flexible Dateiendung
    pattern = re.compile(rf'^{file_prefix}(\d*)\.{file_extension}$')
    files = []
    
    # Dateien im Ordner durchsuchen
    for filename in os.listdir(directory):
        match = pattern.match(filename)
        if match:
            # Wenn keine Nummer da ist (z.B. link_map.csv), ist es 0
            num = int(match.group(1)) if match.group(1) else 0
            files.append((num, filename))

    if not files:
        print(f"No {file_prefix} files found with extension .{file_extension}.")
        return
    
    # Höchste Nummer finden, um die Schleife zu begrenzen
    max_num = max(num for num, _ in files)
    
    # Sequentielles Löschen (wie im Original-Skript)
    for num in range(max_num + 1):
        suffix = str(num) if num > 0 else ''
        filename = f'{file_prefix}{suffix}.{file_extension}'
        filepath = os.path.join(directory, filename)
        
        if os.path.exists(filepath):
            os.remove(filepath)
            print(f"Deleted {filename}")
        else:
            # Falls eine Datei in der Sequenz fehlt
            print(f"File {filename} not found, stopping for {file_prefix}")

# --- Hauptausführung ---

# 1. Lösche link_map Dateien (CSV)
delete_files('link_map', 'csv')

# 2. Lösche routing-tables Dateien (LOG) -> Achtung: Endung ist hier .log
delete_files('routing-tables', 'log')

# 3. Lösche traffic_over_nodes Dateien (CSV)
delete_files('traffic_over_nodes', 'csv')
# BUS-MANAGEMENT-SYSTEM-in-C

A console-based bus management and ticketing system written in C, built as a data
structures course project for a university campus bus service.

## Overview

The bus management system in any organisation is usually subject to tedious work. This
program lets students (users) and the administration of the organisation manage the
buses: students register, check timetables, book rides and pay from a prepaid balance,
while an admin can look up registered members. The admin being able to re-enter bus
details and schedules was planned but is still under progress.

## Features

- **Registration and login**: username, PRN and password, stored in a per-user text
  file (`<username>.txt`) in the working directory
- **Prepaid balance**: check the balance and recharge it
- **Schedule and catalogue**: shows the remaining buses for the current time on routes
  between campus and the city, and the shuttle between the hill base and hill top
- **Book a ride**: simulates swiping a card to board and depart, times the trip and bills
  the fare from the balance
- **Booking history**: lists past rides with bus type and departure time
- **Admin login**: logging in as `admin` opens a menu for checking a member's details

## Project structure

```
membership.cpp   # entry point: main menu, registration, login, admin menu
account.h        # logged-in user menu: balance, recharge, rides, history
DSA_project.h    # bus timetables / "find current bus"
admin.txt        # admin account record
membership.exe   # prebuilt Windows executable
*.h.gch          # precompiled headers (build artefacts)
```

## Getting started

The code uses `conio.h` (`getch()`) and `system("cls")`, so it targets **Windows** with
a compiler such as MinGW/Dev-C++.

Run the prebuilt binary (from `README_INSTRUCTIONS`):

1. Download `account.h`, `DSA_project.h`, `membership.cpp` and `membership.exe`.
2. Save them in one folder.
3. Open `membership.exe` (Windows SmartScreen may warn about an unsigned executable).

Or build it yourself:

```sh
g++ membership.cpp -o membership.exe
```

## Status

Student project from 2016; not actively maintained.

## License

Released under the MIT License. See [LICENSE](LICENSE).

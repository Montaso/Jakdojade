# Jakdojade
A project with implementations of Hashmap and Graph in C++.  
## About
"Jak dojadę" is a console c++ program made as a project for algorithms and data structures subject.  
The main target of writing this was to learn about hashmaps, heaps, graphs and finding shortest paths.  
This project uses Dijkstra's algorithm, priority queue built on a heap, and a hashmap used for storing data.

## Input data  
### Input order
1. X and Y dimensions separated by space sign  
2. a map written with specific instructions **(see below)**  
3. number of flights between cities  
4. flights  
5. number of roads to find
6. roads to find  

### Map
The map must be entered by following these conditions:
- '.' -> empty field
- '*' -> city position
- '#' -> road (each road counts as 1 length unit)
- each city must have a name written next to the city sign (city name must begin or end next to the sign)
- the name must be unambiguous to the city

### Flights  
- flights are only one-way
- user enters a flight with format **"START_CITY DESTINATION_CITY LENGTH"**

### Finding roads
- format **"START_CITY DESTINATION_CITY MODE"**
- mode 0 displays length between two cities
- mode 1 displays cities between desired road
- road is connected only when is next to another road (or city) in X or Y direction

### Example input
> 20 20  
> .........GDANSK.....  //(here city's name is visible)  
> ........\*...........  //('\*' means that the city with the name next to it is placed here)  
> ........#\...........  //('\#' is a road sign and '\.' is an empty field sign)  
> ........#\...........  
> *##################.  
> #SZCZECIN.........#.  
> #.................#.  
> ##................#.  
> .############\*#####.  
> .#...WARSZAWA.......  
> .#..................  
> .#############......  
> .#...........#......  
> .#\..WROCLAW.##......  
> .#..*\.......*\.......  
> .####.......#KIELCE.  
> ......*##.#########.  
> .OPOLE..#\*.......#.  
> ........#.\KRAKOW..#.  
> ........###########.  
> 2  //(number of flights between cities is entered here)  
> KRAKOW GDANSK 10  //(example flight from KRAKOW to GDANSK with length of 10)  
> WARSZAWA WROCLAW 3  
> 3  //(number of roads to find)  
> KRAKOW GDANSK 1  //(example of road find)  
> WARSZAWA WROCLAW 1  
> SZCZECIN KRAKOW 1  
>
### Output for the test above
>10  
3  
29 KIELCE  
>




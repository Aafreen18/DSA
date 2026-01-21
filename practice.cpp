int minCost(
    int numberOfCities,
    int sourceCity,
    int targetCity,
    vector<vector<pair<int,int>>> &adj,  // (neighborCity, fuelRequired)
    vector<int> &fuelPrice,
    int fuelCapacity
) {
    const int INF = 1e9;

    // dist[city][fuelLeft]
    vector<vector<int>> dist(
        numberOfCities,
        vector<int>(fuelCapacity + 1, INF)
    );

    // (totalCost, currentCity, fuelLeft)
    set<tuple<int,int,int>> pq;

    // Start at source with FULL tank
    dist[sourceCity][fuelCapacity] = 0;
    pq.insert({0, sourceCity, fuelCapacity});

    while (!pq.empty()) {
        auto [totalCost, currentCity, fuelLeft] = *pq.begin();
        pq.erase(pq.begin());

        // Ignore outdated state
        if (totalCost > dist[currentCity][fuelLeft]) continue;

        // If target reached, this is minimum cost
        if (currentCity == targetCity) return totalCost;

        /* 🔹 ACTION 1: Buy 1 liter of fuel */
        if (fuelLeft < fuelCapacity) {
            int newCost = totalCost + fuelPrice[currentCity];

            if (newCost < dist[currentCity][fuelLeft + 1]) {
                dist[currentCity][fuelLeft + 1] = newCost;
                pq.insert({newCost, currentCity, fuelLeft + 1});
            }
        }

        /* 🔹 ACTION 2: Travel to neighbors */
        for (auto &edge : adj[currentCity]) {
            int nextCity    = edge.first;
            int fuelRequired = edge.second;

            if (fuelLeft >= fuelRequired) {
                if (totalCost < dist[nextCity][fuelLeft - fuelRequired]) {
                    dist[nextCity][fuelLeft - fuelRequired] = totalCost;
                    pq.insert({totalCost, nextCity, fuelLeft - fuelRequired});
                }
            }
        }
    }

    return -1; // target not reachable
}

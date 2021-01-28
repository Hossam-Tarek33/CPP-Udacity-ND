#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;
    start_node = &m_Model.FindClosestNode(start_x, start_y);
    end_node = &m_Model.FindClosestNode(end_x, end_y);

}

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    return (*node).distance(*end_node);
}


void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
    (*current_node).FindNeighbors();
    for(auto nieghbor : (*current_node).neighbors){
        (*nieghbor).parent = current_node;
        (*nieghbor).g_value = (*current_node).g_value + (*current_node).distance(*nieghbor);
        (*nieghbor).h_value = CalculateHValue(nieghbor);
        open_list.push_back(nieghbor);
        (*nieghbor).visited = true;
    }

}


bool compare(RouteModel::Node *first , RouteModel::Node *second){
    float f1 = (*first).g_value + (*first).h_value;
    float f2 = (*second).g_value + (*second).h_value;
    return f1>f2;
}

RouteModel::Node *RoutePlanner::NextNode() { 
    //sort the openlist from begin to end according to the compare function declared above
    std::sort(open_list.begin(), open_list.end(), compare);
    //set the node in the back of open list as the lowest_f_node and remove it from open list
    RouteModel::Node *lowest_f_node = open_list.back();
    open_list.pop_back();
    return lowest_f_node;
}



std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;
    RouteModel::Node parent;

    // TODO: Implement your solution here.

    //keep searching till a node comes which have no parents "nullptr" == goal
    while((*current_node).parent != nullptr){

        distance = distance + ((*current_node).distance(*((*current_node).parent)));
        //modify path_found vector in order to make start node be the first above and then current_node,then end_node be the last down
        path_found.push_back(*current_node);
        //make the current_node be the parent for next iteration
        current_node =(*current_node).parent;

    }
    path_found.push_back(*current_node);
    std::reverse(path_found.begin(), path_found.end());
    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;

}


void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;
    (*start_node).visited = true;
    //insert the start_node in open_list
    open_list.push_back(start_node);
    //while the open list is not empty 
    while(open_list.size()>0) {
        current_node=NextNode();
        //if the distance from current to end not equal zero or current not at same position of end
        // add nieghbors , otherwise construct the path
        if(((*current_node).distance(*end_node)) != 0 || current_node != end_node){
            AddNeighbors(current_node);
        }
        else
        {
            m_Model.path = ConstructFinalPath(current_node);

       }
        
    }
    

}
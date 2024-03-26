#pragma once
#include "AStarDrawing.h"
#include "AStarGraph.h"
#include "AStarList.h"
#include "AStarNode.h"


namespace AStar
{


class AStarManager
{
public:
	AStarManager(const int width, const int height, const int length);
	AStarManager();
	~AStarManager() = default;

	std::vector<Vector3Pos> GetPath(Vector3Pos startPos, Vector3Pos endPos);
	void DrawAStarGrid() const;
	void DrawAStarDebug(std::vector<Vector3Pos>* path, bool showStartEnd) const;


	void SetDrawing(AStarDrawing* newDrawing) { aStarDrawing = newDrawing; }

	AStarDrawing* GetDrawing() const { return aStarDrawing; }


	AStarGraph aStarGrid;

	int GRID_WIDTH;
	int GRID_HEIGHT;
	int GRID_LENGTH;

	AStarNode startNode;
	AStarNode goalNode;

	AStarList openList;
	AStarList closedList;

	AStarNode current;

private:
	std::vector<Vector3Pos> CalculatePath();

	std::vector<Vector3Pos> calculatedPath ;

	AStarDrawing* aStarDrawing{nullptr};

	//ToDo: rajouter un lissage du chemin
	//ToDo: faire que ça ne prenne pas les diagonales

};

static const double CalculateHeuristic(Vector3Pos posA, Vector3Pos posB)
{

	double dx = abs(posA.x - posB.x);
	double dy = abs(posA.y - posB.y);
	double dz = abs(posA.z - posB.z);

	//ToDo: calculer l'heuristique en 3D

	//Le 1 vaut la distance entre les points(ou cases dans le cas d'une grille)
	double heuristic = 0;
	//heuritic = 1 * (dx + dy) + (sqrt(2) - 2 * 1) * std::min(dx, dy);
	heuristic = 1 * sqrt(dx * dx + dy * dy + dz * dz);
	//heuristic = 1 * (dx + dy + dz);

	return heuristic;
}

static const double CalculateFCostOfNode(Vector3Pos currentNode, Vector3Pos startNode, Vector3Pos goalNode)
{
	//1) Calcul du g cost: Distance du node par rapport au départ(quand diagonal vaut 14, quand droit vaut 10, pour un déplacement de case)
	double gCost = CalculateHeuristic(currentNode, startNode);
	gCost *= 10;
	gCost = round(gCost);
	//2) Calcul du h cost: heursitique: distance du node par rapport au goal(quand diagonal vaut 14, quand droit vaut 10, pour un déplacement de case)
	double hCost = CalculateHeuristic(currentNode, goalNode);
	hCost *= 10;
	hCost = round(hCost);
	// cout << "F cost of calculated Node: " << currentNode.x << " " << currentNode.y << " is: " << gCost << " + " << hCost << " = " << gCost + hCost << endl;

	return gCost + hCost;
}


}

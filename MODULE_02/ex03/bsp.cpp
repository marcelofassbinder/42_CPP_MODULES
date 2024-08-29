#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	if (point == a || point == b || point == c) //se o ponto for um dos vertices
		return false;
	
	Fixed areaABC = a.getArea(b, c);
	
	Fixed areaPAB = point.getArea(a, b);
	Fixed areaPAC = point.getArea(a, c);
	Fixed areaPBC = point.getArea(b, c);

	if (areaPAB != 0 && areaPAC != 0 && areaPBC!= 0) { //se o ponto esta em cima de uma das arestas, uma das areas vai ser 0
		if (areaABC == (areaPAB + areaPAC + areaPBC))//se a soma dos triangulos formados pelo point com a, b, c for igual a area do triangulo abc, retornar true
			return true;
	}
	return false;
}

/*
  val3dity 

  Copyright (c) 2011-2018, 3D geoinformation research group, TU Delft  

  This file is part of val3dity.

  val3dity is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  val3dity is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with val3dity.  If not, see <http://www.gnu.org/licenses/>.

  For any information or further details about the use of val3dity, contact
  Hugo Ledoux
  <h.ledoux@tudelft.nl>
  Faculty of Architecture & the Built Environment
  Delft University of Technology
  Julianalaan 134, Delft 2628BL, the Netherlands
*/


#include "IndoorGraph.h"
#include "definitions.h"
#include "input.h"

namespace val3dity
{

IndoorGraph::IndoorGraph(std::string theid)
{
  if (theid == "")
    _id = "MISSING_ID";
  else
    _id = theid;
  _is_valid = -1;
}


IndoorGraph::~IndoorGraph()
{}


void IndoorGraph::add_vertex(std::string theid, double x, double y, double z, std::string dual, std::vector<std::string> connects)
{
  // std::map<std::string, std::tuple<Point3,std::string,std::vector<std::string>>> _vertices;
  Point3 v(x, y, z);
  _vertices[theid] = std::make_tuple(v, dual, connects);
}

bool IndoorGraph::validate() 
{
  std::cout << "VALIDATE IndoorGraph" << std::endl;
  return true;
  // if (_is_valid != -1)
  //   return _is_valid;
  // bool bValid = Feature::validate_generic(tol_planarity_d2p, tol_planarity_normals, tol_overlap);
  // _is_valid = bValid;
  // return bValid;
}


bool IndoorGraph::is_valid() {
  if (_is_valid == 1) 
    return true;
  else
    return false;
}


std::string IndoorGraph::get_type() {
  return "IndoorGraph";
}


} // namespace val3dity

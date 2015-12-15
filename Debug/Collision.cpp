#include "Collision.h"
#include <stdio.h>

using namespace Game_Lib;

void Collision::CollisionBalltoBall(Ball *ball1,Ball *ball2)
{
	   
	float distance = sqrt(::powf(ball2->Position.x-ball1->Position.x,2)+pow(ball2->Position.y-ball1->Position.y,2)+pow(ball2->Position.z-ball1->Position.z,2));
	
	if (distance < ball1->radius + ball2->radius)
 { 
		
   
  
  Vec3 vector,Normal;
  vector.x = ball1->Position.x - ball2->Position.x;
  vector.y = ball1->Position.y - ball2->Position.y;
  float StandDistance = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z + vector.z));

  
  Normal = vector;
  float normal = VMath::Normalizef(Normal);

  
  float damp = 2.0;

  Vec3 vector2;
  vector2 = VMath::dot(ball2->Velocity*damp, vector);

  

  Vec3 vector1;
  vector1 = VMath::dot(ball1->Velocity*damp, vector);


 
  float e = 0.5;

  Vec3 newvector1,newvector2;

  newvector1 = ((ball1->Mass - e*ball2->Mass)*vector1 + (1+e) *ball2->Mass*vector2)/(ball1->Mass+ball2->Mass);
  newvector2 = ((ball2->Mass - e*ball1->Mass)*vector2 + (1+e) *ball1->Mass*vector1)/(ball1->Mass+ball2->Mass);


  ball1->Velocity +=  (newvector1 - vector1) * Normal;
  ball2->Velocity +=  (newvector2 - vector2) * Normal;
  float touchingDistance = 1;
  float offset = 0.5f * (touchingDistance - normal);

  ball1->Position-= vector - damp;
  ball2->Position += vector - damp;
 }
}
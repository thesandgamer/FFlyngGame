#include "AC_FirstPersonCamera.h"

void AC_FirstPersonCamera::Start()
{
    //-----------Setup les valeurs de la camera------------

    cam.position = Vector3Add(transform->translation, offsetTransform.translation);    //Sa position
    cam.target = { 0.0f, 1.8f, 0.0f };      //où elle regarde
    cam.up = { 0.0f, 1.0f, 0.0f };          //son vecteur up(où est le haut)
    cam.fovy = 65;                       //son field of view
    cam.projection = CAMERA_PERSPECTIVE;    //type de projection


    //--------------Set la base de la camera ----------------
    
    Vector3 v1 = cam.position;
    Vector3 v2 = cam.target;

    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    float dz = v2.z - v1.z;

    camData.targetDistance = sqrtf(dx * dx + dy * dy + dz * dz);   // Distance to target

    // Camera angle calculation
    camData.angle.x = atan2f(dx, dz);                        // Camera angle in plane XZ (0 aligned with Z, move positive CCW)
    camData.angle.y = atan2f(dy, sqrtf(dx * dx + dz * dz));      // Camera angle in plane XY (0 aligned with X, move positive CW)

    camData.playerEyesPosition = cam.position.y;
    
    //-------

    DisableCursor();
    
    /*
    cam.position = { 2.0f, 20.0f, 6.0f };
    cam.target = { 0.0f, 10.0f, 0.0f };      //où elle regarde
    cam.up = { 0.0f, 1.0f, 0.0f };          //son vecteur up(où est le haut)
    cam.fovy = 45.0;                       //son field of view
    cam.projection = CAMERA_PERSPECTIVE;    //type de projection
    SetCameraMode(cam, CAMERA_ORBITAL);*/

}

void AC_FirstPersonCamera::Draw()
{

}

void AC_FirstPersonCamera::Update()
{
   //UpdateCamera(&cam);
   cam.position =Vector3Add( transform->translation ,offsetTransform.translation);

   CameraControl();
}

void AC_FirstPersonCamera::HeadShake(float strength)
{
    // NOT WORKING HAVE TO ADAPT WITH TRANSFORM SYSTEM
    //---------------Head wobble-----------------
    static int swingCounter = 0;    // Used for 1st person swinging movement
    // 
    // If movement detected (some key pressed), increase swinging
    //for (int i = 0; i < 6; i++) if (direction[i]) { swingCounter++; break; }
    swingCounter++;
    cam.position.y = camData.playerEyesPosition - sinf(swingCounter / 8.0f) / 30.0f;

    cam.up.x = sinf(swingCounter / (8.0f * 2)) / 200.0f;
    cam.up.z = -sinf(swingCounter / (8.0f * 2)) / 200.0f;
}

void AC_FirstPersonCamera::CameraControl()
{

    //-------------------Get les values de la souris-----------

    static Vector2 previousMousePosition = { 0.0f, 0.0f };

    Vector2 mousePositionDelta = { 0.0f, 0.0f };
    Vector2 mousePosition = GetMousePosition();

    mousePositionDelta.x = mousePosition.x - previousMousePosition.x;
    mousePositionDelta.y = mousePosition.y - previousMousePosition.y;

    previousMousePosition = mousePosition;

    //-----------------Precalcul -----------------

    //On calcule l'orientation de la camera
    camData.angle.x += (mousePositionDelta.x * -0.003f);
    camData.angle.y += (mousePositionDelta.y * -0.003f);



    //Clamp la camera en hauteur 
    if (camData.angle.y > 89.0f * DEG2RAD) camData.angle.y = 89.0f * DEG2RAD;
    else if (camData.angle.y < -89.0f * DEG2RAD) camData.angle.y = -89.0f * DEG2RAD;


    //----------------------Set la target de la camera------------
    // Recalculate camera target considering translation and rotation
    Matrix translation = MatrixTranslate(0, 0, (camData.targetDistance / 5.1f));
    Matrix rotation = MatrixRotateXYZ({ PI * 2 - camData.angle.y, PI * 2 - camData.angle.x, 0 });
    Matrix transfor = MatrixMultiply(translation, rotation);

    cam.target.x = cam.position.x - transfor.m12;
    cam.target.y = cam.position.y - transfor.m13;
    cam.target.z = cam.position.z - transfor.m14;

    offsetTransform.rotation = QuaternionFromMatrix(transfor);

   // HeadShake(2);



    



}

# RayTracer

## What it is about

In this case it was a school project at 42Born2Code. The task what to first code a raytracer using minimal tools from graphic libraries, in C. In this case our tools were :
- Creating a window
- Create an image and displaying it in the window
- Change the color of a specific pixel in an image
We also could use the math.h lib so we didn't have to code function such as Sine.
Anything else we had to code from scratch.

### Version 1 of the raytracer

List of features:

- Camera can be placed anywhere and rotated
- Multiple spots can be placed in the scene
- Primitives :
	- Cylinder
	- Cone
	- Plane
	- Sphere
- Shadows
- Light shine
- Rotation with quaternions

Once we had the core raytracer working with 4 basic primitives and being able to render with multiple light sources, we had our version 1.

### Final version of the RayTracer

After having that first part done, it was time to start building more features on top of that basic raytracer we had. That is when we had access to more library usage, and so we used the STB to load tga files and GTK to create a UI to help create scenes.

List of new features :
- Reflection for objects
- Refraction for objects
- Sine normal perturbation
- Texture color mapping
- Texture normal mapping
- Checkers mapping (procedural mapping)
- Saving image
- Sepia filter

- Ambiant light
- Parallel light
- User interface to create a scene

- Cutting objects with planes
- Tore added

- Xml library parser

## Conclusion

This was our first 4 people team and the scope of the project took around 4-5 months. For a lot of us who forgot most the math we have learned in high school, having to relearn what was forgotten and learn new math concepts and then applying that into code was what I believe made this project very educational.

# Animation programming
by Sami AMARA and William NARDONNE


## Running the project
Launching `Release/AnimationProgramming.exe` will run the project.
Alternatively, you can open the solution (`AnimationProgramming.sln`) and press F5.
Finally, you can :
1. Open the solution (`AnimationProgramming.sln`)
2. In the solution explorer, left click "AnimationProgramming" under "Solution 'AnimationProgramming'"
3. Click "Build"
4. Wait for the generation to be over
5. Launch `Release/AnimationProgramming.exe`


## What is and is not done
From the subject:
- [X] Dessiner le squelette avec des lignes en utilisant DrawLine (un peu devant le perso afin de voir les lignes) (tag `skeleton_drawing`)
- [X] Déplacer un bone manuellement (tag `move_bone`)
- [X] Coder le hardware skinning pour que les vertices suivent le bones (envoyer les transformations des bones via la fonction SetSkinningPose dans Engine.h) (tag `hardware_skinning`)
- [X] Afficher la première keyframe de l’animation walk sur le personnage (tag `first_keyframe_pose`)
- [X] Faites en sorte que le perso joue l’animation de walk en passant en dur de keyframe à keyframe (tag `raw_animation`)
- [ ] Interpoler les keyframes pour que l’animation soit smooth
- [ ] Blender les animations de walk et run, en contrôlant les vitesses de play des 2 animspour qu’elles soient toujours synchronisées (qu’elles aient le même temps normalisé)

The aformentioned finished versions can be checkout out with `git checkout <tag>`.
The final version is tagged `GOLD`.

## Architecture

![architecture.png](Docs/architecture.png)
*You can find this picture in Docs/*
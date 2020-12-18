# Animation programming
by Sami AMARA and William NARDONNE


## Running the project
Launching `Release/AnimationProgramming.exe` will open the project.

The make changes into the project and regenerate it:
- Open AnimationProgramming.sln
- Make sure Visual Studio is in Release x86
- In the solution explorer, left click "Animation Programming" under "Solution 'Animation Programming'"
- Click Build
- Wait for the generation to be over
- Open `Release/AnimationProgramming.exe`

You can eventually launch the Debugger if that works for you.

## What is and is not done
From the subject:
- [X] Dessiner le squelette avec des lignes en utilisant DrawLine (un peu devant le perso afin de voir les lignes) (tag `skeleton_drawing`)
- [X] Déplacer un bone manuellement (tag `move_bone`)
- [X] Coder le hardware skinning pour que les vertices suivent le bones (envoyer les transformations des bones via la fonction SetSkinningPose dans Engine.h) (tag `hardware_skinning`)
- [X] Afficher la première keyframe de l’animation walk sur le personnage (tag `first_keyframe_pose`)
- [ ] Faites en sorte que le perso joue l’animation de walk en passant en dur de keyframe à keyframe
    - You can comment/uncomment lines commented with "/* Uncomment to test raw walk animation */" to try it, be we were unable to test it
- [ ] Interpoler les keyframes pour que l’animation soit smooth
- [ ] Blender les animations de walk et run, en contrôlant les vitesses de play des 2 animspour qu’elles soient toujours synchronisées (qu’elles aient le même temps normalisé)


The finished version can be checkout out with `git checkout <tag>`

## Architecture

![architecture.png](Docs/architecture.png)
*You can find this picture in Docs/*
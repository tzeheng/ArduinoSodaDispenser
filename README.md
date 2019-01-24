# Arduino Soda Dispenser
*January 24, 2019 -- Tze Heng Tan*  
This repository will contain the design specification, documentation and codes for Julius' soda dispenser. To be made out of cardboard, hotglue and controlled by an Arduino Uno controller 
## Overview
### Problem
1. **YouTube nerds**: Countless YouTube videos and channels constantly supplying Julius with nerdy ideas of things to make, such as this [soda dispenser](https://www.youtube.com/watch?v=k0ERi0Bt8Gk).
2. **Automation is a must**: A 'manual' [dispenser such as this](https://www.youtube.com/watch?v=Ek0GqIr99X8) isn't enough. It has to be a *robot* (automatic).
3. **Daily SCRUMs**: The project manager, Julius, organized daily SCRUM and demands constant updates and progress reports.
> Are you finally fixing my cola machine?  
> Can you put lights and buttons on it now?  
> When will it be done?  
### Goals
1. Design and create a structure strong enough to hold the beverage, dispensing mechanism and electronics out of cardboard.
2. Design and approval of dispensing mechanism
3. Programming and testing of the dispensing mechanism
4. Deliver product on time before the enthusiasm runs out
### Out of scope
1. Decision on how the components will be reused for future projects
2. Product lifecycle management
3. Warranty of any kind
### People and roles
* **JJ - Project manager**: Oversight and approval of progress and projects
* **CW - Mechanical engineer**: Design and manufacture of the housing unit
* **TT - Control and operations**: Everything else 
## Specifications
### Body and structure
**Material**: Cardboard boxes, double or tripple fortified if necessary. Hot glue.
**Technical drawing**: *to be updated*
**Tests**: Robustness test - ability to hold 1L soda bottles
### Dispensing mechanism
Two variants will be tested:
* Gravity-driven dispensing with electronic valve and pressure equalization. *Risks: might not be suitable for carbonated drinks as they might lose carbonation over time due to open design of the pressure equalization. Possible alternative: a second valve*
* Positive-pressure dispensing using a vacuum pump.
**Tests**: leaks, realiability and dispensing volume precision.
### Controller
* Arduino Uno
* Dispensing to be button-triggered
* Circuits will be delivered as prototype package (breadboards and jumper-wires) in a semi-secure and waterproof enclosure to prevent tempering and will **not** be soldered on development boards.
* LEDs and LCD display
## Action items
- [x] Finalization of design specification
- [ ] Sourcing of components
- [ ] Cardboard structure
- [ ] Dispensing mechanism
- [ ] Micro-controller
- [ ] QC and testing
- [ ] Product delivery
- [ ] Project closure



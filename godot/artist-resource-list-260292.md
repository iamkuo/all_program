# Artist Resource List for Battle System Test

This document provides a comprehensive list of all visual and audio resources needed for the Godot battle system project, organized by category with specifications for the artist.

## Project Overview
- **Game Type**: Tower defense/card battle hybrid
- **Engine**: Godot 4.x
- **Visual Style**: 2D pixel art or vector graphics
- **Teams**: Player (Team 0) vs Opponent (Team 1)
- **Lanes**: 3 combat lanes (Top, Middle, Bottom)

## Recommended Asset Organization Structure

```
assets/
├── animations/
│   ├── units/
│   │   ├── archer/
│   │   │   ├── idle.png
│   │   │   ├── walk.png
│   │   │   ├── attack.png
│   │   │   └── die.png
│   │   ├── mage/
│   │   │   └── [same animations]
│   │   └── warrior/
│   │       └── [same animations]
│   └── effects/
│       ├── projectile_trail.png
│       ├── explosion.png
│       └── hit_flash.png
├── audio/
│   ├── music/
│   │   ├── battle_theme.mp3
│   │   └── victory_theme.mp3
│   └── sfx/
│       ├── unit_spawn.wav
│       ├── attack_melee.wav
│       ├── attack_ranged.wav
│       ├── hit.wav
│       ├── death.wav
│       ├── tower_destroy.wav
│       ├── elixir_gain.wav
│       ├── card_select.wav
│       ├── card_deploy.wav
│       └── error.wav
├── fonts/
│   ├── main_font.ttf (already exists)
│   ├── ui_font.ttf (already exists)
│   └── damage_font.ttf (already exists)
├── images/
│   ├── backgrounds/
│   │   ├── main_menu_bg.png
│   │   ├── battle_bg.png
│   │   └── victory_bg.png
│   ├── characters/
│   │   ├── units/
│   │   │   ├── archer_player.png
│   │   │   ├── archer_enemy.png
│   │   │   ├── mage_player.png
│   │   │   ├── mage_enemy.png
│   │   │   ├── warrior_player.png
│   │   │   └── warrior_enemy.png
│   │   └── towers/
│   │       ├── tower_player.png
│   │       └── tower_enemy.png
│   ├── environment/
│   │   ├── tiles/
│   │   │   ├── ground_tiles.png (tileset)
│   │   │   ├── trail_tiles.png (tileset)
│   │   │   ├── building_tiles.png (tileset)
│   │   │   └── hill_tiles.png (tileset)
│   │   ├── decorations/
│   │   │   ├── trees.png
│   │   │   ├── rocks.png
│   │   │   └── bushes.png
│   │   └── structures/
│   │       ├── bridges.png
│   │       └── barriers.png
│   ├── objects/
│   │   ├── projectiles/
│   │   │   ├── arrow.png
│   │   │   ├── magic_projectile.png
│   │   │   └── sword_slash.png
│   │   └── items/
│   │       ├── elixir_orb.png
│   │       └── power_ups.png
│   ├── particles/
│   │   ├── dust.png
│   │   ├── smoke.png
│   │   ├── spark.png
│   │   └── blood.png
│   └── ui/
│       ├── cards/
│       │   ├── card_background.png
│       │   ├── card_archer_icon.png
│       │   ├── card_mage_icon.png
│       │   ├── card_warrior_icon.png
│       │   ├── cost_badge.png
│       │   └── card_hover.png
│       ├── panels/
│       │   ├── panel_border.png
│       │   ├── elixir_bar.png
│       │   ├── health_bar.png
│       │   └── dialog_box.png
│       ├── buttons/
│       │   ├── button_normal.png
│       │   ├── button_hover.png
│       │   ├── button_pressed.png
│       │   └── button_disabled.png
│       ├── icons/
│       │   ├── elixir_icon.png
│       │   ├── attack_icon.png
│       │   ├── defense_icon.png
│       │   ├── speed_icon.png
│       │   └── range_icon.png
│       └── hud/
│           ├── selection_circle.png
│           ├── target_reticle.png
│           └── damage_numbers.png
└── spritesheets/
    ├── units_spritesheet.png (optional combined format)
    └── effects_spritesheet.png (optional combined format)
```

## Detailed Resource Specifications

### 1. Unit Characters (Priority: HIGH)

#### Archer (Ranged Unit)
- **Animations Required**:
  - **Idle**: 4-6 frames, breathing animation
  - **Walk**: 6-8 frames, side-view walking
  - **Attack**: 4-6 frames, drawing bow and shooting
  - **Die**: 4-6 frames, death animation

#### Mage (Ranged Magic Unit)
- **Animations Required**: Same as Archer

#### Warrior (Melee Tank Unit)
- **Animations Required**: Same as Archer

**Animation Notes**:
- All animations should support horizontal flipping
- Frame rate: 8-12 FPS for smooth playback
- Sprite should face right by default
- Export as individual PNG files or spritesheet

### 2. Towers (Priority: HIGH)

#### Player Tower
- **Style**: Fortified structure
- **States**: Normal, damaged (optional), destroyed (optional)
- **Health Bar**: Integrated or separate UI element

#### Enemy Tower
- **Style**: Fortified structure
- **States**: Same as player tower
- **Health Bar**: Integrated or separate UI element

### 3. Projectiles (Priority: MEDIUM)

#### Arrow (Archer Projectile)
- **Style**: Simple arrow shape
- **Animation**: Optional rotation or trail effect

#### Magic Projectile (Mage Projectile)
- **Style**: Glowing orb or energy bolt
- **Animation**: Pulsing or trailing effect

#### Melee Effect (Warrior Attack)
- **Style**: Slash arc or impact flash
- **Animation**: Quick flash effect

### 4. UI Elements (Priority: HIGH)

#### Card System
- **Card Background**: Bordered panel
- **Card Icons**: For each unit type
- **Cost Badge**: Small overlay showing elixir cost
- **Card Hover State**: Highlighted version
- **Card Selected State**: Active version

#### Panels & Borders
- **Dialog Panel**: Scalable 9-slice border
- **Elixir Bar**: Horizontal progress bar
- **Health Bar**: Horizontal progress bar
- **UI Panel**: Generic bordered container

#### Buttons
- **Normal State**: Default appearance
- **Hover State**: Highlighted appearance
- **Pressed State**: Active appearance
- **Disabled State**: Dimmed appearance

#### Icons
- **Elixir Icon**: Small droplet or orb
- **Attack Icon**: Sword or crosshair
- **Defense Icon**: Shield
- **Speed Icon**: Wing or lightning
- **Range Icon**: Target or radar

#### HUD Elements
- **Selection Circle**: Ring around selected units
- **Target Reticle**: Crosshair for targeting
- **Damage Numbers**: Sprite sheet for floating damage text

### 5. Environment Tiles (Priority: MEDIUM)

#### Ground Tiles
- **Format**: Tileset atlas
- **Variations**: Grass, dirt, stone, path
- **Transitions**: Edge tiles for blending

#### Trail/Path Tiles
- **Format**: Tileset atlas
- **Style**: Dirt path, stone road
- **Transitions**: Path to grass edges

#### Building Tiles
- **Format**: Tileset atlas
- **Style**: Walls, roofs, structures
- **Variations**: Different building types

#### Hill/Elevation Tiles
- **Format**: Tileset atlas
- **Style**: Hills, cliffs, elevation
- **Transitions**: Slope tiles

### 6. Backgrounds (Priority: MEDIUM)

#### Main Menu Background
- **Style**: Epic battle scene or game logo
- **Format**: PNG with transparency support

#### Battle Background
- **Style**: Battlefield or arena
- **Format**: PNG with transparency support

#### Victory/Defeat Screens
- **Style**: Celebratory or dramatic
- **Format**: PNG with transparency support

### 7. Particle Effects (Priority: LOW)

#### Combat Particles
- **Dust**: Small particles for movement
- **Smoke**: For explosions/death
- **Spark**: For hit effects
- **Blood**: For damage indication (optional)

#### Magic Particles
- **Magic Trail**: For mage projectiles
- **Cast Effect**: For spell casting
- **Impact**: For magic hits

### 8. Audio Assets (Priority: MEDIUM)

#### Music
- **Battle Theme**: Loopable, 2-3 minutes, energetic
- **Victory Theme**: Short fanfare, 30-60 seconds
- **Defeat Theme**: Somber, 30-60 seconds
- **Menu Theme**: Calm, 2-3 minutes

#### Sound Effects
- **Unit Spawn**: Magical summon sound
- **Attack Melee**: Sword swing or impact
- **Attack Ranged**: Bow release or magic cast
- **Hit**: Impact sound
- **Death**: Unit death sound
- **Tower Destroy**: Explosion/collapse
- **Elixir Gain**: Resource collection
- **Card Select**: UI click
- **Card Deploy**: Unit placement
- **Error**: Invalid action

**Audio Specifications**:
- Format: WAV or OGG
- Music: 44.1kHz, stereo
- SFX: 44.1kHz, mono or stereo
- Keep file sizes reasonable (< 1MB per SFX)

## Technical Requirements

### Image Formats
- **Preferred**: PNG with transparency
- **Sprites**: PNG-24 for quality
- **UI**: PNG-24 or PNG-8 with transparency
- **Backgrounds**: JPG or PNG (no transparency needed)

### Resolution Guidelines
- Assets should scale appropriately for various screen resolutions

### Animation Guidelines
- **Frame Rate**: 8-12 FPS for 2D sprites
- **Looping**: Idle and walk should loop seamlessly
- **Timing**: Attack animations should be 0.3-0.5 seconds
- **Transitions**: Smooth between states

## File Naming Conventions

- Use lowercase with underscores
- Descriptive names (e.g., `archer_idle_01.png`)
- Team variants: `archer_player.png`, `archer_enemy.png`
- Animation frames: `walk_01.png`, `walk_02.png`, etc.
- UI states: `button_normal.png`, `button_hover.png`

## Delivery Format

### Preferred Delivery
- Individual PNG files for each asset
- Organized in the folder structure above
- Include a master spritesheet if using combined format
- Provide source files (PSD, AI, etc.) for future edits

### Optional Extras
- Style guide document
- Animation timing reference
- Concept art for reference

## Current Asset Inventory

The following assets already exist and may need replacement or enhancement:

### Existing Characters
- goblin_bow.png, goblin_player.webp, goblin_staff.png, goblin_summon.png
- slime.png, slime_green.png, slime_purple.png
- house.png, npc.webp, world_tree.png

### Existing UI
- Multiple panel border styles (01-16 Border variants)
- UI elements (buttons, icons, panels)
- Main menu background

### Existing Audio
- 1 music track (time_for_adventure.mp3)
- 5 SFX files (coin, explosion, hurt, jump, power_up, tap)

### Existing Environment
- Floor tiles, landscape tiles, wall tiles
- Decorative elements
- Object sprites

## Priority Order for Asset Creation

1. **Phase 1 (Critical)**:
   - Unit sprites (Archer, Mage, Warrior - both teams)
   - Unit animations (idle, walk, attack, die)
   - Tower sprites (both teams)
   - Card icons and backgrounds
   - Basic UI panels

2. **Phase 2 (Important)**:
   - Projectile sprites
   - Environment tiles
   - Battle background
   - Health/elixir bars
   - Selection/target indicators

3. **Phase 3 (Polish)**:
   - Particle effects
   - Additional UI states
   - Victory/defeat screens
   - Audio assets
   - Decorative elements

## Notes for Artist

- The game uses a lane-based combat system (3 lanes)
- Units need to be distinguishable at a glance
- Player units should clearly differ from enemy units
- UI should be readable at various screen sizes
- Maintain consistent art style across all assets
- Assets should scale well for different resolutions
- Keep file sizes reasonable for performance

## Contact Information

If you have questions about specifications, technical requirements, or need clarification on any asset, please contact the development team.

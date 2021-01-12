let enemyPresets = ["Pirate", "Gunner"];

function scopedUniqueId()
{
    var internalIdCounter = 0;
    return function(reset = false)
    {
        if (reset) internalIdCounter = 0;
        return "uid_" + internalIdCounter++;
    }
}
var uniqueId = scopedUniqueId();

function presetChange(e)
{
    document.getElementById("input-type").value = e.target.value;
}

function clearParameters()
{
    document.getElementById("input-type").value = "";
    document.getElementById("input-x").value = 0;
    document.getElementById("input-y").value = 0;
    document.getElementById("input-timer").value = 0;
}

function createEnemyElement(type, pos, timer)
{
    let enemyBox = document.createElement("div");
    enemyBox.setAttribute("draggable", "true");
    enemyBox.addEventListener("dragstart", handleDragStart, false);
    enemyBox.addEventListener("dragend", handleDragEnd, false);
    enemyBox.innerHTML = `
        <table>
            <tr class="enemy-table-header-row">
                <th>Type</th>
                <th>Position</th>
                <th>Timer</th>
            </tr>
            <tr>
                <td>${type}</td>
                <td>{${pos.x}, ${pos.y}}</td>
                <td>${timer}ms</td>
            </tr>
        </table>
    `;
    enemyBox.dataset["type"] = type;
    enemyBox.dataset["x"] = pos.x;
    enemyBox.dataset["y"] = pos.y;
    enemyBox.dataset["timer"] = timer;
    enemyBox.classList.add("enemy-box");
    return enemyBox;
}

createEnemy();
function createEnemy()
{
    data = {};
    data.type = document.getElementById("input-type").value;
    data.pos = {};
    data.pos.x = ~~document.getElementById("input-x").value;
    data.pos.y = ~~document.getElementById("input-y").value;
    data.timer = ~~document.getElementById("input-timer").value;

    if (data.type == "")
    {
        data.type = "Enemy";
    }

    let enemyBox = createEnemyElement(data.type, data.pos, data.timer);

    let spawner = document.getElementById("enemy-spawner");
    spawner.innerHTML = "";
    spawner.appendChild(enemyBox);

    console.log(data);
}

function addPackListeners(pack)
{
    if (pack)
    {
        if (pack.id == "")
            pack.id = uniqueId();
        pack.addEventListener("dragenter", handleDragEnter, false);
        pack.addEventListener("dragleave", handleDragLeave, false);
    }
}

addFunctionalityToExistingPacks();
function addFunctionalityToExistingPacks()
{
    uniqueId(true); // Reset id counter
    addPackListeners(document.getElementById("trashcan"));
    document.querySelectorAll(".pack").forEach(function(pack) {
        addPackListeners(pack);
    });
}

let drag = { active: true, id: undefined, parent: undefined };
// Enemy-Box
function handleDragStart(e)
{
    if (drag.active) return false;
    drag.active = true;

    drag.parent = this.parentNode;

    this.style.opacity = 0.4;
}
// Enemy-Box
function handleDragEnd(e)
{
    this.style.opacity = 1;
    drag.active = false;

    // Handle "drop"
    if (drag.id)
    {
        let container = document.getElementById(drag.id);
        if (container.classList.contains("trashcan"))
        {
            this.remove();
        }
        else
        {
            container.appendChild(this);
        }
    }
}

// Pack
function handleDragEnter(e)
{
    this.classList.add("drag-over");
    drag.id = this.id;
}
// Pack
function handleDragLeave(e)
{
    this.classList.remove("drag-over");
}

// Download file to Client
function downloadToFile(content, filename, contentType)
{
    const file = new Blob([content], { type: contentType });

    const a = document.createElement("a");
    a.href = URL.createObjectURL(file);
    a.download = filename;
    a.click();

    URL.revokeObjectURL(a.href);
}

// Save level to file
function exportLevel()
{
    let data = { "Packs": [] };

    let packElements = document.getElementById("level-window").children;
    [...packElements].forEach(function(packElement)
    {
        let pack = {
            "ExitCondition": {
                "Type": "WaitTillAllEnemiesAreDead"
            },
            "Enemies": []
        };

        [...packElement.children].forEach(function(enemyElement, i)
        {
            let enemy = {
                type: null,
                position: { x: null, y: null },
                timer: null
            };

            enemy.type = enemyElement.dataset["type"];
            enemy.timer = ~~enemyElement.dataset["timer"];
            enemy.position.x = ~~enemyElement.dataset["x"];
            enemy.position.y = ~~enemyElement.dataset["y"];

            pack["Enemies"].push(enemy);
        })

        data["Packs"].push(pack);
    });

    downloadToFile(JSON.stringify(data) + "\n", "level_x", "application/json");
}

// Read file
function importLevel(e)
{
    const file = e.target.files[0];
    document.getElementById("file-name").textContent = file.name;
    const reader = new FileReader();
    reader.onload = function (e)
    {
        let content = JSON.parse(e.target.result);
        console.log(content);

        // Clear packs
        document.getElementById("level-window").innerHTML = "";

        // Add packs
        content.Packs.forEach(function(packObject, i)
        {
            // Create pack elemet
            let pack = document.createElement("div");
            pack.classList.add("pack");

            // Add enemies
            packObject.Enemies.forEach(function(enemyObject)
            {
                console.log(enemyObject);
                pack.appendChild(createEnemyElement(enemyObject.type, enemyObject.position, enemyObject.timer));
            });

            document.getElementById("level-window").appendChild(pack);
        });

        addFunctionalityToExistingPacks();
    }
    reader.readAsText(file);
}
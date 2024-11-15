#include "player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

Player::Player()
{
    jumpSpeed = 20; // Adjust this for higher jumps
    gravity = 1;    // Controls fall speed
    verticalVelocity = 0;
    isJumping = false;
    // inserting an image of mario to convert it into item
    QPixmap playerimage (" C:/Users/hemac/Downloads/ImageToStl.com_image (1).png");
    // this is setting the weight and height
    playerimage= playerimage.scaled(10,20);
    // making a pointer under QGraphicsPixmapItem class.
    QGraphicsPixmapItem * Playeritem = new QGraphicsPixmapItem;
    // setting its poisition in the scene.
    Playeritem->setPos(20,30);
    // linking the image to the item
    Playeritem->setPixmap(playerimage);
        // adding the item to the scene;
    scene()->addItem(Playeritem);
    // this is to make the player (active item) is the focused item to allow it be moved by key presses.
    Playeritem->setFlags(QGraphicsItem::ItemIsFocusable);
    Playeritem->setFocus();

};

void Player::keyPressEvent(QKeyEvent *event)
{
    // *******  Event Handling for the Player ********
    if (event->key() == Qt::Key_Left) {
        if (x()
            > 0) // to prevent the player from getting out of the screem, these numbers will be changed according to what will be done in the scene
        {
            setPos(x() - 10, y());
        }
    } else if (event->key() == Qt::Key_Right)

    {
        if (x() + 100
            < 800) // to prevent the player from getting out of the screen, these numbers will be changed according to what will be done in the scene
            setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_Space) {
        jump();
    }
}

void Player::jump()
{
    if (!isJumping) { // Ensure Mario can’t jump again mid-air
        verticalVelocity = -jumpSpeed;
        isJumping = true;
    }
}
void Player::updatePosition()
{
    if (isJumping) {
        verticalVelocity += gravity; // Apply gravity
        //y()+verticalVelocity;        // Update y-position

        //if (y >= groundLevel) {       // Detect collision with the ground
        //y = groundLevel;
        //verticalVelocity = 0;
        //isJumping = false;
        //}
    }
    //setPos(x, y); // Update position on the screen
}

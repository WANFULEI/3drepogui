/**
 *  Copyright (C) 2015 3D Repo Ltd
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "repoprojectmanagerdialog.h"
#include "ui_repoabstractmanagerdialog.h"

repo::gui::RepoProjectManagerDialog::RepoProjectManagerDialog(
        const core::MongoClientWrapper &mongo,
        const string &database,
        QWidget *parent)
    : RepoAbstractManagerDialog(mongo, database, parent)
{
    setWindowTitle("Project Manager");

    //--------------------------------------------------------------------------
    // Users
    model->setColumnCount(6);
    model->setHeaderData(
                Columns::PROJECT,
                Qt::Horizontal,
                tr("Project"));
    model->setHeaderData(
                Columns::DESCRIPTION,
                Qt::Horizontal,
                tr("Description"));
    model->setHeaderData(
                Columns::OWNER,
                Qt::Horizontal,
                tr("Owner"));
    model->setHeaderData(
                Columns::PERMISSIONS,
                Qt::Horizontal,
                tr("Permissions"));
    model->setHeaderData(
                Columns::TYPE,
                Qt::Horizontal,
                tr("Type"));
    model->setHeaderData(
                Columns::USERS,
                Qt::Horizontal,
                tr("Users"));

    ui->treeView->sortByColumn(Columns::PROJECT, Qt::SortOrder::AscendingOrder);
    clear();
}

repo::gui::RepoProjectManagerDialog::~RepoProjectManagerDialog()
{

}
